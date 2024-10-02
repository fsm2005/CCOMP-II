<?php
$servidor = "localhost";
$usuario = "root";
$clave = "";
$baseDeDatos = "datosform";
$enlace = mysqli_connect($servidor, $usuario, $clave, $baseDeDatos);

if (!$enlace) {
    die("Conexión fallida: " . mysqli_connect_error());
}
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulario de Registro</title>
</head>
<body>
    <h1>Formulario de Registro</h1>

    <form action="" method="POST">
        <label for="nombre">Nombre y Apellidos:</label>
        <input type="text" id="nombre" name="nombre" required><br><br>

        <label for="fecha_nacimiento">Fecha de Nacimiento:</label>
        <input type="date" id="fecha_nacimiento" name="fecha_nacimiento" required><br><br>

        <label for="ocupacion">Ocupación:</label>
        <input type="text" id="ocupacion" name="ocupacion" required><br><br>

        <label for="contacto">Contacto (Teléfono) :</label>
        <input type="text" id="contacto" name="contacto" required><br><br>

        <label for="nacionalidad">Nacionalidad:</label>
        <select id="nacionalidad" name="nacionalidad" required>
            <option value="argentina">Argentina</option>
            <option value="mexico">México</option>
            <option value="peru">Peru</option>
            <option value="chile">Chile</option>
            <option value="colombia">Colombia</option>
        </select><br><br>

        <label>Nivel de Inglés:</label><br>
        <input type="radio" id="basico" name="nivel_ingles" value="básico" required>
        <label for="basico">Básico</label><br>
        <input type="radio" id="intermedio" name="nivel_ingles" value="intermedio">
        <label for="intermedio">Intermedio</label><br>
        <input type="radio" id="avanzado" name="nivel_ingles" value="avanzado">
        <label for="avanzado">Avanzado</label><br>
        <input type="radio" id="fluido" name="nivel_ingles" value="fluido">
        <label for="fluido">Nativo</label><br><br>

        <label for="lenguajes">Lenguajes de Programación:</label><br>
        <select id="lenguajes" name="lenguajes_programacion[]" multiple required>
            <option value="c++">C++</option>
            <option value="python">Python</option>
            <option value="java">Java</option>
            <option value="php">PHP</option>
            <option value="javascript">JavaScript</option>
        </select><br><br>

        <label for="aptitudes">Aptitudes (escribe una y selecciona):</label>
        <input list="aptitudesList" id="aptitudes" name="aptitudes">
        <datalist id="aptitudesList">
            <option value="Trabajo en equipo">
            <option value="Comunicación">
            <option value="Liderazgo">
            <option value="Resolución de problemas">
        </datalist><br><br>

        <label>Habilidades:</label><br>
        <input type="checkbox" id="habilidad1" name="habilidades[]" value="Diseño web">
        <label for="habilidad1">Diseño web</label><br>
        <input type="checkbox" id="habilidad2" name="habilidades[]" value="Desarrollo backend">
        <label for="habilidad2">Desarrollo backend</label><br>
        <input type="checkbox" id="habilidad3" name="habilidades[]" value="Base de datos">
        <label for="habilidad3">Base de datos</label><br>
        <input type="checkbox" id="habilidad4" name="habilidades[]" value="Análisis de datos">
        <label for="habilidad4">Análisis de datos</label><br><br>

        <label for="perfil">Perfil:</label><br>
        <textarea id="perfil" name="perfil" rows="4" cols="50"></textarea><br><br>

        <input type="submit" name="registro" value="Enviar">
    </form>
</body>
</html>

<?php
if (isset($_POST['registro'])) {
    $nombre = htmlspecialchars($_POST['nombre']);
    $fecha_nacimiento = htmlspecialchars($_POST['fecha_nacimiento']);
    $ocupacion = htmlspecialchars($_POST['ocupacion']);
    $contacto = htmlspecialchars($_POST['contacto']);
    $nacionalidad = htmlspecialchars($_POST['nacionalidad']);
    $nivel_ingles = htmlspecialchars($_POST['nivel_ingles']);
    $lenguajes_programacion = implode(", ", $_POST['lenguajes_programacion']);
    $aptitudes = htmlspecialchars($_POST['aptitudes']);
    $habilidades = implode(", ", $_POST['habilidades']);
    $perfil = htmlspecialchars($_POST['perfil']);

    $insertarDatos = "INSERT INTO datacv (nombre, fecha_nacimiento, ocupacion, contacto, nacionalidad, nivel_ingles, lenguajes_programacion, aptitudes, habilidades, perfil) 
                      VALUES ('$nombre', '$fecha_nacimiento', '$ocupacion', '$contacto', '$nacionalidad', '$nivel_ingles', '$lenguajes_programacion', '$aptitudes', '$habilidades', '$perfil')";

    if (mysqli_query($enlace, $insertarDatos)) {
        echo "Datos registrados correctamente";
    } else {
        echo "Error: " . mysqli_error($enlace);
    }
}
mysqli_close($enlace);
?>


<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $nombre = htmlspecialchars($_POST['nombre']);
    $fecha_nacimiento = htmlspecialchars($_POST['fecha_nacimiento']);
    $ocupacion = htmlspecialchars($_POST['ocupacion']);
    $contacto = htmlspecialchars($_POST['contacto']);
    $nacionalidad = htmlspecialchars($_POST['nacionalidad']);
    $nivel_ingles = htmlspecialchars($_POST['nivel_ingles']);
    $lenguajes_programacion = implode(", ", $_POST['lenguajes_programacion']);
    $aptitudes = htmlspecialchars($_POST['aptitudes']);
    $habilidades = implode(", ", $_POST['habilidades']);
    $perfil = htmlspecialchars($_POST['perfil']);

    $cv_path = 'CVmuestra.html';

    $cv_content = file_get_contents($cv_path);
    $cv_content = str_replace("<!-- NOMBRE -->", $nombre, $cv_content);
    $cv_content = str_replace("<!-- OCUPACION -->", $ocupacion, $cv_content);
    $cv_content = str_replace("<!-- CONTACTO -->", $contacto, $cv_content);
    $cv_content = str_replace("<!-- NACIONALIDAD -->", $nacionalidad, $cv_content);
    $cv_content = str_replace("<!-- FECHAS -->", $fecha_nacimiento, $cv_content);
    $cv_content = str_replace("<!-- NIVEL_INGLES -->", $nivel_ingles, $cv_content);
    $cv_content = str_replace("<!-- LENGUAJES_PROGRAMACION -->", $lenguajes_programacion, $cv_content);
    $cv_content = str_replace("<!-- APTITUDES -->", $aptitudes, $cv_content);
    $cv_content = str_replace("<!-- HABILIDADES -->", $habilidades, $cv_content);
    $cv_content = str_replace("<!-- PERFIL -->", $perfil, $cv_content);

    file_put_contents($cv_path, $cv_content);

    header("Location: $cv_path");
    exit();
}
?>
