'use strict';

angular.module('mean.viewport').directive('cpp', ['modelService', '$http', '$timeout', function(modelService, $http, $timeout) {
    return {
        template: '<textarea id="cpptext"> </textarea>',
        replace: true,
        link: function($scope, element, attrs) {
            $scope.modelService = modelService;

            var codeMirrorHeader = CodeMirror.fromTextArea($('#cpptext')[0], {
                lineNumbers: true,
                mode: "clike",
                theme: 'blackboard',
                textWrapping: true,
                readOnly: true
            });

            $scope.$watch('modelService.currentModel', _.debounce(function() {
                $http.post('/api/viewport/models/cpp', {model:modelService.currentModel}).then(function(cpp) {
                    var code = cpp.data;

                    $scope.currentCpp = code;
                    $timeout(function() {
                        $scope.currentCpp = code;
                    });

                    if(code.header) {
                        codeMirrorHeader.setValue('// -- Header Code -- \n' + code.header);
                    } else {
                        codeMirrorHeader.setValue(JSON.stringify(code, null, 2));
                    }
                }, function(error) {
                    codeMirrorHeader.setValue(JSON.stringify(error, null, 2));
                })
            }, 500));

            $scope.$watch('viewport', function(viewport) {
                if(viewport !== 'C++') {
                    $(codeMirrorHeader.getWrapperElement()).hide();
                } else {
                    $(codeMirrorHeader.getWrapperElement()).show(400, function() {
                        codeMirrorHeader.refresh();
                    });
                }
            });
        }
    };
}]);
