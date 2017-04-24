# Estructura_Proyecto

<b>Flujo de trabajo</b>

Para descargar el archivo, en consola usar el comando:
<pre>$ git clone https://github.com/kirovxq/Estructura_Proyecto.git
$ cd Estructura_Proyecto</pre>

Pueden crear sus ramas directamente con:
<pre>$ git branch [nombre de rama]
$ git checkout [nombre de rama]</pre>

La compilación de los archivos dentro de Files se hace con

<pre>$ gcc *.h *.c</pre>

Cuando terminen de modificar, guarden sus cambios y despues usen los siguientes comandos:
<pre>$ git add .
$ git commit -m "titulo de las modificaciones"</pre>
*No olviden actualizar a la última versión de los archivos
<pre>$ git pull origin master</pre>
Las modificaciones se suben al repositorio remoto (el de github) con el siguiente comando:
<pre>$ git push origin [nombre de rama]</pre>
