<?hh //strict
namespace Opes;

/**
 *    System:: dependencies belonging to the system
 *      >> spl_autoload comes later. Need to group and make components
 */
// -->Request: parse incomming request
  require __DIR__.'/Http/Request.hh';
  require __DIR__.'/Http/Headers/RequestHeader.hh';
  require __DIR__.'/Http/Headers/GET.hh';
  require __DIR__.'/Http/Headers/POST.hh';
  require __DIR__.'/Http/Headers/PUT.hh';
  require __DIR__.'/Http/Headers/PATCH.hh';
  require __DIR__.'/Http/Headers/DELETE.hh';

// -->Routes: prepare local routes
  require __DIR__.'/Http/Router.hh';

// -->Response: generate output
  require __DIR__.'/Http/Response.hh';

// -->UserAccessControl: init
  require __DIR__.'/UAC/User.hh';


/**
 *    App:: app inner workings << custom work
 */


// -->Route: my routes
  require __DIR__.'/../app/Routes/api.hh';
  require __DIR__.'/../app/Routes/www.hh'; // angular2 web route
