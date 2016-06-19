'use strict';

angular.module('mean.viewport').directive('execute', ['$http', '$timeout', 'modelService', function($http, $timeout, modelService) {
    return {
        template: '<button class="btn" ng-class="btnClass" ng-disabled="disableButton" ng-click="execute()">Execute</button>',
        replace: true,
        link: function($scope, element, attrs) {
            $scope.btnClass = "btn-danger";
            $scope.disableButton = false;

            $scope.execute = function() {
                $scope.btnClass = "btn-warning";
                $scope.disableButton = true;

                var useOpenCl = $scope.executeTarget === 'OpenCL';
                var target = '/api/viewport/execute/' + (useOpenCl ? 'opencl' : 'cpp');

                $http.post(target, {model:modelService.currentModel}).then(function(response) {
                    $scope.executeResult = response.data;
                    $timeout(function() {
                        $scope.executeResult = response.data;
                        $scope.btnClass = "btn-success";

                        $timeout(function() {
                            $scope.btnClass = "btn-danger";
                            $scope.disableButton = false;
                        }, 1000);
                    });
                }, function(error) {
                    $scope.executeResult = error;
                    $scope.btnClass = "btn-danger";
                    $timeout(function() {
                        $scope.disableButton = false;
                    }, 1000);
                })
            };
        }
    };
}]);
