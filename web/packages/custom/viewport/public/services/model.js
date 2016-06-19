'use strict';

angular.module('mean.viewport').factory('modelService', [
  function() {

    var properties = [
      'State Variables',
      'State Initialisation',
      'Model Parameters',
      'State Index',
      'Random Source',
      'State Update',
      'Output'
    ];

    var alignedProperties = [
      //'Model Parameters'
    ];

    function ModelBuilder() {
      var builder = this;

      properties.forEach(function(property) {
        builder['with' + property.replace(/ /g,'')] = function(value) {
          builder[property] = builder[property] || [];
          builder[property].push(value);
          return builder;
        }
      });

      this.build = function() {
        return properties.reduce(function(acc, next) {
          if(acc.length) {
            acc += '\n';
          }

          acc += '% ' + next + '\n';

          (builder[next] || []).forEach(function(value) {
            acc += value + '\n';
          });

          return acc;
        }, '');
      }
    }

    function TeXBuilder() {
      this.tex = '';

      this.withSection = function(section) {
        if(this.aligning) {
          this.tex += '\\end{align}\\\\[2em]\n\n';
          this.aligning = false;
        } else {
          if (this.tex.length) {
            this.tex = this.tex.substring(0, this.tex.length - 1);
            this.tex += '[2em]\n\n';
          }
        }

        this.tex += '\\mathbf{\\text{' + section + '}}\\\\\n';

        if(_.contains(alignedProperties, section)) {
          this.aligning = true;
          this.tex += '\\begin{align}'
        }

        return this;
      };

      this.withLine = function(line) {
        if(this.aligning) {
          line = line.replace(/=/g, '&=');
        }

        this.tex += line + '\\\\\n';

        return this;
      };

      this.build = function() {
        return this.tex;
      };
    }

    function parseModel(input) {
      var builder = new ModelBuilder();

      var lines = input.split('\n');
      var currentProperty = 'State Variables';

      lines.forEach(function(line) {
        if(!line.length) {
          return;
        }

        if(_.contains(properties, line.substring(2))) {
          currentProperty = line.substring(2);
        } else {
          var withFunc = builder['with' + currentProperty.replace(/ /g,'')];

          if(withFunc) {
            withFunc(line);
          }
        }
      });

      return builder;
    };

    function modelBuilderToTeX(model) {
      var builder =  new TeXBuilder();

      properties.forEach(function(property) {
        var lines = model[property] || [];

        if(lines.length) {
          builder.withSection(property);
        }

        lines.forEach(builder.withLine.bind(builder))
      });

      return builder.build();
    }

    function randomWalk() {
      return new ModelBuilder()
          .withStateVariables('price')
          .withStateInitialisation('price_{0} = 100')
          .withModelParameters('Simulations = 10')
          .withModelParameters('Steps = 10')
          .withRandomSource('random \\sim Z[-1,1]')
          .withStateIndex('t \\in [1..Steps]')
          .withStateUpdate('price_{t + 1} = price_{t} + random_{t}')
          .withOutput('price_{t + 1}')
          .build();
    }


    function geometricWalk() {
      return new ModelBuilder()
          .withStateVariables('price')
          .withStateInitialisation('price_{0} = 100.0')
          .withModelParameters('Simulations = 10')
          .withModelParameters('Steps = 10')
          .withRandomSource('random \\sim R[-1,1]')
          .withStateIndex('t \\in [1..Steps]')
          .withStateUpdate('price_{t + 1} = price_{t} + (price_{t} * random_{t})')
          .withOutput('price_{t}')
          .build();
    }

    function blackScholes() {
      return new ModelBuilder()
          .withStateVariables('logspot')
          .withStateInitialisation('logspot_{0} = 100.0')
          .withModelParameters('Simulations = 10')
          .withModelParameters('Steps = 10')
          .withModelParameters('vol = 0.2')
          .withModelParameters('drift = -0.1')
          .withModelParameters('dt = 0.2')
          .withRandomSource('r \\sim N[0,1]')
          .withStateIndex('t \\in [1..Steps]')
          .withStateUpdate('logspot_{t + 1} = logspot_{t} + drift + vol * \\sqrt{dt} * r_{t}')
          .withOutput('logspot_{t}')
          .build();
    }

    function termVol() {
      return new ModelBuilder()
          .withStateVariables('logspot')
          .withStateInitialisation('logspot_{0} = 100.0')
          .withModelParameters('Simulations = 10')
          .withModelParameters('Steps = 3')
          .withModelParameters('vol = [0.2, 0.3, 0.6]')
          .withModelParameters('drift = [-0.2, 0.8, 0.0]')
          .withModelParameters('dt = [0.1, 0.5, 0.3]')
          .withRandomSource('r \\sim N[0,1]')
          .withStateIndex('t \\in [1..Steps]')
          .withStateUpdate('logspot_{t + 1} = logspot_{t} + drift_{t} + vol_{t} * \\sqrt{dt_{t}} * r_{t}')
          .withOutput('logspot_{t}')
          .build();
    }

    function heston() {
      return new ModelBuilder()
          .withStateVariables('logspot')
          .withStateVariables('variance')
          .withStateInitialisation('logspot_{0} = 100.0')
          .withStateInitialisation('variance_{0} = 5.0')
          .withModelParameters('Simulations = 10')
          .withModelParameters('Steps = 3')
          .withModelParameters('kappa = [0.2, 0.3, 0.6]')
          .withModelParameters('theta = [-0.2, 0.8, 0.0]')
          .withModelParameters('epsilon = [0.1, 0.5, 0.3]')
          .withModelParameters('dt = [0.1, 0.9, 0.3]')
          .withModelParameters('minVar = 0.0')
          .withRandomSource('r \\sim N[0,1]')
          .withRandomSource('r2 \\sim N[0,1]')
          .withStateIndex('t \\in [1..Steps]')
          .withStateUpdate('logspot_{t + 1} = logspot_{t} + 0.5 * dt_{t} * variance_{t} + \\sqrt{variance_{t}} * \\sqrt{dt_{t}} * r_{t}')
          .withStateUpdate('variance_{t + 1} = variance_{t} +  0.5 * kappa_{t} * (theta_{t} - \\max{variance_{t}}{minVar}) + epsilon_{t} * \\sqrt{\\max{variance_{t}}{minVar}} * \\sqrt{dt_{t}} * r2_{t}')
          .withOutput('logspot_{t}')
          .build();
    }

      function izhikevichNeurons() {
          return new ModelBuilder()
              .withStateVariables('v')
              .withStateVariables('u')
              .withStateInitialisation('v_{0} = -50.0')
              .withStateInitialisation('u_{0} = 10.0')
              .withModelParameters('Simulations = 3')
              .withModelParameters('Steps = 1000')
              .withModelParameters('a = 0.02')
              .withModelParameters('b = 0.2')
              .withModelParameters('c = -65.0')
              .withModelParameters('d = 8.0')
              .withModelParameters('I = 20.0')
              .withRandomSource('r \\sim R[0.02,0.3]')
              .withStateIndex('t \\in [1..Steps]')
              .withStateUpdate('v_{t + 1} = v_{t} >= 30 ? c : v_{t} + r_{t} * (0.04 * v_{t} * v_{t} + 5 * v_{t} + 140 - u_{t} + I)')
              .withStateUpdate('u_{t + 1} = v_{t} >= 30 ? u_{t} + d : u_{t} + r_{t} * (a * (b * v_{t} - u_{t}))')
              .withOutput('v_{t}')
              .build();
      }

      function izhikevichBurstingNeurons() {
          return new ModelBuilder()
              .withStateVariables('v')
              .withStateVariables('u')
              .withStateInitialisation('v_{0} = -50.0')
              .withStateInitialisation('u_{0} = 10.0')
              .withModelParameters('Simulations = 1')
              .withModelParameters('Steps = 2000')
              .withModelParameters('a = 0.02')
              .withModelParameters('b = 0.3')
              .withModelParameters('c = -54.0')
              .withModelParameters('d = 1.0')
              .withModelParameters('I = 3.0')
              .withRandomSource('r \\sim R[0.18,0.2]')
              .withStateIndex('t \\in [1..Steps]')
              .withStateUpdate('v_{t + 1} = v_{t} >= 30 ? c : v_{t} + r_{t} * (0.04 * v_{t} * v_{t} + 5 * v_{t} + 140 - u_{t} + I)')
              .withStateUpdate('u_{t + 1} = v_{t} >= 30 ? u_{t} + d : u_{t} + r_{t} * (a * (b * v_{t} - u_{t}))')
              .withOutput('v_{t}')
              .build();
      }

    var service = {
      set currentModel(model) {
        this.currentTeX = modelBuilderToTeX(parseModel(model));
        this._currentModel = model;
      },

      get currentModel() {
        return this._currentModel;
      }
    };

    service.currentModel = randomWalk();

    service.randomWalk = randomWalk;
    service.geometricWalk = geometricWalk;
    service.blackScholes = blackScholes;
    service.termVol = termVol;
    service.heston = heston;
    service.izhikevichNeurons = izhikevichNeurons;
    service.izhikevichBurstingNeurons = izhikevichBurstingNeurons;

    return service;
  }
]);
