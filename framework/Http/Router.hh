<?hh //strict

namespace Opes\Http;

/**
 *  Router:: get all the defined routes and match them with $callbacks
 *
 */

type options = shape(
     'prefix' => string
   );

type root = shape(
    'root' => string
  );
type defaults = shape(
    'root' => string
  );
type group = shape(
    'list' => route
  );
type route = shape(
    'path' => string,
    'method' => string,
    'component' => string,
    'controller' => string
  );

class Router{
  public static array<string,mixed> $routes = array();
  // private static array<string,mixed> $default;


  public function __construct(){
    # code...
  }
  public static function addZone(string $slug, group $r, options $o) : void{
      //if (!self::$routes[$o['prefix']]) self::$routes[$o['prefix']] = $r;
      //else
      var_dump($r);
  }
  public static function updateZone(Map<string,mixed> $r) : void{

  }
  public static function removeZone(Map<string,mixed> $r) : void{

  }
  // -->Set: options
  public static function options(options $r) : void{

  }
}
