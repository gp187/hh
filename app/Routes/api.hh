<?hh

/*
    Define the Routes and "Controllers"

    TODO:: find appropriate notation for routes and controllers with
*/


//var_dump(get_declared_classes());

// -->Set: default options
Opes\Http\Router::options(Map{
    'prefix' => 'api/v1'
});

// -->Set: route block
Opes\Http\Router::addZone(Map{
    'root' => 'user',
    'children' => [
        Map{
            'path' => 'list',
            'component' => Opes\UAC\User::class,
            'controller' => "list"
        },
        Map{
            'path' => 'profile/@userId',
            'component' => Opes\UAC\User::class,
            'controller' => "profile"
        }
      ]
});
