<!DOCTYPE html>
<html> 
<head>
    <title>Selected Doctor</title> 
    <link rel="stylesheet" href="style.css">
  </head>

  <body> 
    <h2>Patients</h2>

    <table>
        <tr>
            <th>Nurse ID</th>
            <th>Nurse Name</th>
            <th>Patient ID</th>
            <th>Patient Name</th>
        </tr>


<?php

include "config.php";
if(isset($_POST['ids']))
{
    $selection_id = $_POST['ids'];
    $sql_statement = "SELECT P.pid, P.pname, N.nname, N.nid FROM patient P, nurse N, takecare_of G WHERE P.pid = '$selection_id' AND P.pid = G.pid AND N.nid = G.nid";
    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $pid = $row['pid'];
        $pname = $row['pname'];
        $md_id = $row['nid'];
        $md_name = $row['nname'];

        echo "<tr>" . "<th>" . $md_id . "</th>" . "<th>" . $md_name . "</th>" . "<th>" . $pid . "</th>" .  "<th>" . $pname . "</th>" . "</tr>";
    }

    //header("Location: index.php");
?>
</table>
<br><br><br>

<h2>Doctors</h2>

    <table>
        <tr>
            <th>Nurse ID</th>
            <th>Doctor ID</th>
            <th>Doctor Name</th>
            <th>Doctor Area</th>
        </tr>

<?php
    $sql_statement = "SELECT W.nid, D.md_id, D.dname, D.darea
    FROM  Doctor D, works_with W
    WHERE  '$selection_id' = W.nid AND D.md_id = W.md_id";

    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['nid'];
        $nname = $row['dname'];
        $nid = $row['md_id'];
        $narea = $row['darea'];
        
        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $nid . "</th>" . "<th>" . $nname . "</th>"  ."<th>" . $narea . "</th>". "</tr" . "<br>";
        //echo $mysender . "<br>" . $message . "<br><br>";
    }
?>
</table>
<br><br><br>

<?php
}
else
{
    echo "The form is not set";
}
?>

<br><br><br><br>
<div align="left">
<form action="nurse.php">
        <button class = "gfg" type="submit">
            Nurse main page
        </button>
</form>
</div>


    
</body>
</html>