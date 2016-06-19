'use strict';

angular.module('mean.viewport').directive('result', ['modelService', function(modelService) {
    return {
        template: '<textarea id="result"> </textarea>',
        replace: true,
        link: function($scope, element, attrs) {

            var codeMirror = CodeMirror.fromTextArea($('#result')[0], {
                lineNumbers: true,
                mode: "clike",
                theme: 'blackboard',
                textWrapping: true,
                readOnly: true
            });

            function toggleEditor() {
                var result = $scope.executeResult;

                if(!result || $scope.resultView !== 'Data') {
                    $(codeMirror.getWrapperElement()).hide();
                } else {
                    codeMirror.setValue(result.split ? result : JSON.stringify(result, null, 2));

                    $(codeMirror.getWrapperElement()).show(400, function() {
                        codeMirror.refresh();
                    });
                }
            }

            $scope.$watch('executeResult', toggleEditor);
            $scope.$watch('resultView', toggleEditor);
        }
};
}]);
