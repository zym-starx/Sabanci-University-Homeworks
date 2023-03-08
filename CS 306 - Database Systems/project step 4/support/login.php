<?php

error_reporting(E_ALL ^ E_DEPRECATED);
$link = mysqli_connect("localhost", "root", "", "cs306project");




// Check connection
if($link === false){
    die("ERROR: Could not connect. " .mysqli_connect_error());
}


$adminid=$_POST['adminid']; //this is what we get from the form.
$pass=$_POST['pass'];


if(empty($_POST['adminid']) || empty($_POST['pass'])   )
{
  echo "<script>alert('You have an empty field.');</script>";

    header("Refresh:0; url=index.html");   // go back to the login page
}

if(isset($_POST['log']))
{
    
    if($adminid == NULL)   // if there is no such user like that.
    {
      echo "<script>alert('The ID does not exist');</script>";
      header("Refresh:0; url=index.html");   // go back to the login page
    } 
    
    //else if($adminid!= "cs306" || $pass!= "database")
    //{
    //  echo "<script>alert('The password or the username is incorrect');</script>";
    //  header("Refresh:0; url=index.html");
    //}

    else if($adminid== "cs306" && $pass== "database")
    {
      
      header("Refresh:0; url=chat-admin.php");
    }
    
    else{
      header("Refresh:0; url=supportmenu.php");
    }
}

?>