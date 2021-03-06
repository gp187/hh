<?hh

/*
    Define the Routes and "Controllers"

    TODO:: find appropriate notation for routes and controllers with
*/


//var_dump(get_declared_classes());

// -->Set: default options
Opes\Http\Router::options(shape('prefix' => 'api/v1'));


// -->Set: route block
Opes\Http\Router::addZone('user', ImmMap{
    'list' => shape(
          'path' => 'list',
          'method' => Opes\Http\HttpMethod::GET,
          'component' => Opes\UAC\User::class, // << main class to access
          'controller' => "list" // << function to run to generate output {$component}->Controller
      ),
    'show/me/the/money' => shape(
          'path' => 'list',
          'method' => Opes\Http\HttpMethod::GET,
          'component' => Opes\UAC\User::class, // << main class to access
          'controller' => "list" // << function to run to generate output {$component}->Controller
      ),
    'profile/@userId' => shape(
          'path' => 'profile/@userId',
          'method' => Opes\Http\HttpMethod::GET,
          'component' => Opes\UAC\User::class,
          'controller' => "profile"
      )
}, shape('prefix' => 'api/v1', 'component' => Opes\UAC\User::class));

Opes\Http\Router::addZone('article', ImmMap{
    'list' => shape(
          'path' => 'list',
          'method' => Opes\Http\HttpMethod::GET,
          'component' => Opes\UAC\User::class,
          'controller' => "list" // << function to run to generate output {$component}->Controller
      )
}, shape('prefix' => 'api/v1'));
