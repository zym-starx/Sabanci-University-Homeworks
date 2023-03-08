<?php

include "config.php";
if(isset($_POST['ids']))
{
    $selection_id = $_POST['ids'];
    $sql_statement = "DELETE FROM Patient WHERE pid = $selection_id";
    $result = mysqli_query($db, $sql_statement);

    header("Location: deletepatient.php");
}

else
{
    echo "The form is not set";
}

?>