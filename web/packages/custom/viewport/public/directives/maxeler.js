'use strict';

angular.module('mean.viewport').directive('maxeler', ['modelService', '$http', '$timeout', function(modelService, $http, $timeout) {
    return {
        template: '<textarea id="maxelertext"> </textarea>',
        replace: true,
        link: function($scope, element, attrs) {
            $scope.modelService = modelService;

            var codeMirrorHeader = CodeMirror.fromTextArea($('#maxelertext')[0], {
                lineNumbers: true,
                mode: "clike",
                theme: 'blackboard',
                textWrapping: true,
                readOnly: true
            });

            $scope.$watch('modelService.currentModel', _.debounce(function() {
                $http.post('/api/viewport/models/maxeler', {model:modelService.currentModel}).then(function(max) {
                    var code = max.data;

                    $scope.currentMaxeler = code;
                    $timeout(function() {
                        $scope.currentMaxeler = code;
                    });

                    if(code.kernel) {
                        codeMirrorHeader.setValue(/*'// -- C Code -- \n' + code.c.join('\n') +
                            '\n\n*/'// -- Kernel Code -- \n' + code.kernel +
                            '\n\n// -- Manager Code -- \n' + code.manager);
                    } else {
                        codeMirrorHeader.setValue(JSON.stringify(code, null, 2));
                    }
                }, function(error) {
                    codeMirrorHeader.setValue(JSON.stringify(error, null, 2));
                })
            }, 500));

            $scope.$watch('viewport', function(viewport) {
                if(viewport !== 'Maxeler FPGA') {
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
