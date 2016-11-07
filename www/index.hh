<?hh //decl
// -->Start: the framework
require __DIR__.'/../framework/Start.hh';

// -->Register: controllers
use Opes\Http\Request as Request;
use Opes\UAC\User as User;

// var_dump(getallheaders());
// var_dump($_GET);
// var_dump($_POST);
// var_dump($_REQUEST);

// -->Register: the app
$app = new Request($_SERVER, $_COOKIE, $_GET, $_POST, $_FILES);
//echo "Da";

echo "<br>Request:";
var_dump($app->request->json);
echo "<br>";
// var_dump($app->server);
echo "<br>";
echo "<br>Path:";
var_dump($app->path);
echo "<br>";
echo "<br>";
