var app = angular.module("app", [])
.controller("myController", [
    "$scope",
    function ($scope) {
        $scope.name = "Fred Flintstone"
        $scope.person = {
            firstname: "Fred",
            lastname: "flintstone"
        }
        $scope.title = "something"
        $scope.renameTitle = function (newValue) {
            $scope.title = newValue
        }
    }
])