'use strict';

angular.module('mean.viewport').directive('viewport', ['modelService', '$timeout', function(modelService, $timeout) {
    return {
        template: '<div id="MathOutput" style="max-width:100%" ng-show="viewport === \'LaTeX\'">$$ ' + modelService.currentTeX + ' $$</div>',
        replace: true,
        link: function($scope, element, attrs) {
            $scope.modelService = modelService;

            var ready = function() {
                $('#MathOutput').fadeIn(200);
            };

            var notReady = function(math) {
                return function() {
                    $('#MathOutput').fadeOut(200, function() {
                        MathJax.Hub.Queue(["Text", math, "\\displaystyle{" + modelService.currentTeX + "}"], ready);
                    });
                }
            };

            $('#MathOutput').hide();

            var first = true;
            $scope.$watch('modelService.currentTeX', _.debounce(function() {
                var math = MathJax.Hub.getAllJax("MathOutput")[0];

                if(math) {
                    if(first) {
                        first = false;
                    } else {
                        MathJax.Hub.Queue(notReady(math));
                    }
                }
            }, 500));

            $timeout(function() {
                MathJax.Hub.Queue(['Typeset', MathJax.Hub], ready);
            });
        }
    };
}]);
