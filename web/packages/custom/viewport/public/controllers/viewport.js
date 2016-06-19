'use strict';

/* jshint -W098 */
angular.module('mean.viewport').controller('ViewportController', ['$scope', 'Global', 'Viewport',
  function($scope, Global, Viewport) {
    $scope.global = Global;
    $scope.package = {
      name: 'viewport'
    };

    $scope.viewport = "LaTeX";
  }
]);
