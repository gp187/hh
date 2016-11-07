<?hh //strict

namespace Opes\Http {


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


type settings = shape(
     'prefix' => string,
     'component' => string
   );

type route = shape(
    'path' => string,
    'method' => HttpMethod,
    'component' => \Opes\Base\TController,
    'controller' => string
  );
const string DS = '/';


class Router{
  public static ImmMap<string,route> $routes = ImmMap{};
  public static Set<string> $prefixes = Set{};
  public static Set<string> $paths = Set{};
  private static ImmMap<string,string> $defaults = ImmMap{
    'prefix' => 'api/v1'
  };
  public function __construct(): void{}

  /*
      addZone :: add routing zone to the current route list
  */
  public static function addZone(string $slug, ImmMap <string,route> $r, settings $o): bool{
      // -->Set: route
      $routes = Map{};
      $prefix = DS.Shapes::idx($o, 'prefix', self::$defaults->get('prefix'));
      if (!self::$prefixes->contains($prefix)) self::$prefixes->add($prefix);
      $route = DS.$slug;
      // -->Iterate
      $iterator = $r->getIterator();
      // -->Loop
      while($iterator->valid()) {
          // -->Add: full path
          $key = $route.DS.$iterator->key();
          self::$paths->add($key);
          // -->Make: route object
          $routes->add(Pair{(string) $key, $iterator->current() });
          // -->Next
          $iterator->next();
      }
      self::$routes = $routes->toImmMap();

      var_dump(self::$routes);

      return true;
  }
  /*
    updateZone:: update existing zone
  */
  public static function updateZone(ImmMap<string,mixed> $r): void{

  }
  /*
    removeZone:: delete existing zone
  */
  public static function removeZone(ImmMap<string,mixed> $r): void{

  }

  /*
    validateRoute :: get current route and see if you can find an associated function
  */
  public static function routeExists(string $route): bool {
      $validPrefix = false;

      // -->Match: the current prefix to one of the authorized ones
      $it = self::$prefixes->getIterator();
      while($it->valid()) {
          if (startsWith($route, $it->current())) {
            $route = explode(DS, (string) str_replace($it->current(), "", $route));
            $validPrefix = true;
            break;
          }
          $it->next();
      }

      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function
      // -->TODO:: get the route object and return it so I can use it and call the object and function 

      if (!$validPrefix) return false;
      // -->Match: the route to $route shape
      $it = self::$routes->getIterator();
      while ($it->valid()) {
          $rr = explode(DS, $it->key());

      }

      return false;
  }
  // -->Set: options
  public static function options(settings $r) : void{

  }
}
}
