app.controller('menuController', [
    '$scope',
    function ($scope) {
        $scope.model = {title: 'Our Menu'};
        
        $scope.$watch('model.mainDish', function(newValue, oldValue) {
            if (newValue === 'BBQ Chicken Pizza') {
                alert('You have selected the BBQ Chicken Pizza!');
            }
        });

        $scope.menu = {
            Cheese: {name: "Cheese Pizza", price: 11.3},
            Pepperoni: {name: "Pepperoni Pizza", price: 11.3},
            Margherita: {name: "Margherita Pizza", price: 11.3},
            BBQ: {name: "BBQ Chicken Pizza", price: 11.3},
            Combo: {name: "Combo Pizza", price: 11.3}
        }

        $scope.changeMainDish = function (item) {
            $scope.model.mainDish = item.name;
            $scope.model.price = "$" + item.price;
        }
    }
]);