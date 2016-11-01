<?hh //strict

namespace Opes\Http;

/**
 *  Router:: get all the defined routes and match them with $callbacks
 *
 */

enum HttpMethod: string {
    GET = "GET";
    POST = "POST";
    PUT = "PUT";
    PATCH = "PATCH";
    DELETE = "DELETE";
}

type options = shape(
     'prefix' => string
   );

type route = shape(
    'path' => string,
    'method' => HttpMethod,
    'component' => \Opes\Base\TController,
    'controller' => string
  );


class Router{

  public function __construct(
    public Map<string,Map<string,route>> $routes = Map{}
  ){
    # code...
  }
  public static function addZone(string $slug, Map <string,route> $r, options $o) : void{
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
