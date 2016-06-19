'use strict';

angular.module('mean.viewport').directive('chart', ['modelService', function(modelService) {
    return {
        template: '<svg id="chart" style="height: 400px"></svg>',
        replace: true,
        link: function($scope, element, attrs) {
            function draw() {
                nv.addGraph(function() {
                    var chart = nv.models.lineChart()
                            .margin({left: 100})  //Adjust chart margins to give the x-axis some breathing room.
                            .useInteractiveGuideline(true)  //We want nice looking tooltips and a guideline!
                            .showLegend(false)       //Show the legend, allowing users to turn on/off line series.
                            .showYAxis(true)        //Show the y-axis
                            .showXAxis(true)        //Show the x-axis
                        ;

                    chart.xAxis     //Chart x-axis settings
                        .axisLabel('State Index')
                        .tickFormat(d3.format(',r'));

                    chart.yAxis     //Chart y-axis settings
                        .axisLabel('Output')
                        .tickFormat(d3.format('.02f'));

                    /* Done setting the chart up? Time to render it!*/
                    var myData = formatData();   //You need data...

                    d3.select('#chart')    //Select the <svg> element you want to render the chart in.
                        .datum(myData)         //Populate the <svg> element with chart data...
                        .call(chart);          //Finally, render the chart!

                    //Update the chart when window resizes.
                    nv.utils.windowResize(function() { chart.update() });
                    return chart;
                });
            }

            function formatData() {
                var data = $scope.executeResult;

                var keys = _.filter(Object.keys(data), function(key) {
                    return _.startsWith(key, "simulation");
                });

                return keys.map(function(simulation) {
                    return {
                        key: simulation,
                        values: data[simulation].map(function (value, i) {
                            return {
                                x: i,
                                y: value
                            }
                        })
                    }
                });
            }

            function toggleChart() {
                var result = $scope.executeResult;

                if(!result || $scope.resultView !== 'Chart') {
                    $('#chart').hide();
                } else {
                    $('#chart').show(400, draw);
                }
            }

            $scope.$watch('executeResult', toggleChart);
            $scope.$watch('resultView', toggleChart);
        }
};
}]);
