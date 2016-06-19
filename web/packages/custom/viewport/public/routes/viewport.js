'use strict';

angular.module('mean.viewport').config(['$stateProvider',
  function($stateProvider) {
    $stateProvider.state('viewport', {
      url: '/models/',
      templateUrl: 'viewport/views/index.html'
    });
  }
]);
