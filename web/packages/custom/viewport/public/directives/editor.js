'use strict';

angular.module('mean.viewport').directive('editor', ['modelService', '$timeout', function(modelService, $timeout) {
    return {
        template: '<textarea>' + modelService.currentModel + '</textarea>',
        replace: true,
        link: function($scope, element, attrs) {
            var codeMirror = CodeMirror.fromTextArea(element[0], {
                lineNumbers: true,
                mode: "stex",
                theme: 'blackboard',
                textWrapping: true
            });

            codeMirror.on('change', function(model) {
                $timeout(function() {
                    $scope.executeResult = undefined;
                    modelService.currentModel = codeMirror.getValue();
                });
            });

            $scope.$watch('selectedModel', function(model) {
                var model =
                    model === "Random Walk" ?  modelService.randomWalk() :
                    model === "Geometric Walk" ? modelService.geometricWalk() :
                    model === "Black Scholes" ? modelService.blackScholes() :
                    model === "Term Vol" ? modelService.termVol() :
                    model === "Heston" ? modelService.heston() :
                    model === "Izhikevich Excitatory Neurons" ? modelService.izhikevichNeurons() : modelService.izhikevichBurstingNeurons();

                codeMirror.setValue(model);
            });
        }
    };
}]);
