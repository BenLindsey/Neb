'use strict';

angular.module('mean.viewport').directive('opencl', ['modelService', '$http', '$timeout', function(modelService, $http, $timeout) {
    return {
        template: '<textarea id="opencltext"> </textarea>',
        replace: true,
        link: function($scope, element, attrs) {
            $scope.modelService = modelService;

            var codeMirrorHeader = CodeMirror.fromTextArea($('#opencltext')[0], {
                lineNumbers: true,
                mode: "clike",
                theme: 'blackboard',
                textWrapping: true,
                readOnly: true
            });

            $scope.$watch('modelService.currentModel', _.debounce(function() {
                $scope.disableButton = true;
                $timeout(function() {
                    $scope.disableButton = true;
                });

                $http.post('/api/viewport/models/opencl', {model:modelService.currentModel}).then(function(openCL) {
                    var code = openCL.data;

                    $scope.currentOpenCL = code;
                    $scope.disableButton = false;
                    $timeout(function() {
                        $scope.currentOpenCL = code;
                        $scope.disableButton = false;

                        if($scope.executeDueToChangedModel) {
                            $scope.executeDueToChangedModel = false;
                            if(_.isFunction($scope.execute)) {
                                $scope.execute();
                            }
                        }
                    });

                    if(code.kernel) {
                        codeMirrorHeader.setValue('// -- Kernel Code -- \n' + code.kernel +
                            '\n\n// -- Header Code -- \n' + code.header);
                    } else {
                        codeMirrorHeader.setValue(JSON.stringify(openCL.data, null, 2));
                    }
                }, function(error) {
                    codeMirrorHeader.setValue(JSON.stringify(error, null, 2));
                })
            }, 500));

            $scope.$watch('selectedModel', function() {
                $scope.executeDueToChangedModel = true;
            });

            $scope.$watch('viewport', function(viewport) {
                if(viewport !== 'OpenCL') {
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
