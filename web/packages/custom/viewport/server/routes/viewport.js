'use strict';

var fs = require('fs');
var sys = require('sys');
var exec = require('child_process').exec;

var COMPILER_ROOT = "/home/DSL/compiler";
var BUILD_ROOT= "/tmp";

function buildCommand(modelFileName, target, flags) {
    flags = flags || [];

    return COMPILER_ROOT + "/run.sh " + modelFileName + " " + target + " " + BUILD_ROOT +"" + flags.join(" ");
}

function sendFiles(files, buildDir, res, buffer) {
    var buffer = buffer || {};
    var file = files.pop();

    console.log('reading file: ' + file.location);
    fs.readFile(buildDir + "/" + file.location, 'utf8', function(err, data) {
        if(err) {
            return res.send(err);
        } else {
            buffer[file.key] = data;

            if(files.length) {
                sendFiles(files, buildDir, res, buffer);
            } else {
                console.log(buffer);
                return res.send(buffer);
            }
        }
    });
}

function runSimulation(dir, res) {
    exec("make -C " + dir, function (error, stdout, stderr) {
        console.log('stdout: ' + stdout);
        console.log('stderr: ' + stderr);

        if (error !== null) {
            console.log('build error: ' + error);
            res.send('build error: ' + error);
        } else {
            exec(dir + "/a.out", function (error, stdout, stderr) {
                console.log('stdout: ' + stdout);
                console.log('stderr: ' + stderr);

                if (error !== null) {
                    console.log('run error: ' + error);
                    res.send('run error: ' + error);
                } else {
                    res.send(stdout);
                }
            });
        }
    });
}

function executeModel(name, model, target, res, files) {
    var modelFileName = "/tmp/" + name + ".neb";
    var buildDir = BUILD_ROOT + "/" + target + "_" + name;

    fs.writeFile(modelFileName, model, function(err) {
        if(err) {
            return res.send(err);
        }

        var command = buildCommand(modelFileName, target);

        console.log("Executing: ", command);

        exec(command, function (error, stdout, stderr) {
            console.log('stdout: ' + stdout);
            console.log('stderr: ' + stderr);

            if (error !== null) {
                console.log('exec error: ' + error);
                res.send('exec error: ' + error);
            } else {
                if(files) {
                    sendFiles(files, buildDir, res);
                } else {
                    runSimulation(buildDir, res);
                }
            }
        });
    });
}

module.exports = function(Viewport, app, auth, database) {

    app.post('/api/viewport/models/cpp', function(req, res) {
        executeModel("cppModel", req.body.model, "cpp", res, [
            {key: "header", location: "MonteCarlo.h"}
        ]);
    });

    app.post('/api/viewport/models/opencl', function(req, res) {
	    executeModel("openCLModel", req.body.model, "openCL", res, [
            {key: "header", location: "MonteCarlo.h"},
            {key: "kernel", location: "Template.cl"}
        ]);
    });

    app.post('/api/viewport/models/maxeler', function(req, res) {
        executeModel("maxelerModel", req.body.model, "fpga", res, [
            {key: "kernel", location: "EngineCode/src/nebstream/NebStreamKernel.maxj"},
            {key: "manager", location: "EngineCode/src/nebstream/NebStreamManager.maxj"}
        ]);
    });

    app.post('/api/viewport/execute/cpp', function(req, res) {
        executeModel("cppModel", req.body.model, "cpp", res);
    });

    app.post('/api/viewport/execute/opencl', function(req, res) {
        executeModel("openCL", req.body.model, "cpp", res);
    });

  app.get('/api/viewport/example/auth', auth.requiresLogin, function(req, res, next) {
    res.send('Only authenticated users can access this');
  });

  app.get('/api/viewport/example/admin', auth.requiresAdmin, function(req, res, next) {
    res.send('Only users with Admin role can access this');
  });

  app.get('/api/viewport/example/render', function(req, res, next) {
    Viewport.render('index', {
      package: 'viewport'
    }, function(err, html) {
      //Rendering a view from the Package server/views
      res.send(html);
    });
  });
};
