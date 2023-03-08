<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="style.css">
</head>
<body>
    <h2>Patient Management</h2>
    <table>
        <th>
        <form action="viewby-patient.php" method="POST">
            <button type="submit">View Patient</button>
        </form>
        </th>
        <th>
        <form action="selectpatient.php" method="POST">
            <button type="submit">Select Patient</button>
        </form>
        </th>
        <th>
        <form action="addpatient.php" method="POST">
            <button type="submit">Add Patient</button>
        </form>
        </th>
        <th>
        <form action="deletepatient.php" method="POST">
            <button type="submit">Delete Patient</button>
        </form>
        </th>
        

    </table>
    
    <?php
        include "listpatients.php";
    ?>


<br><br><br>
<div align="left">
    <form action="index.html">
            <button class = "gfg" type="submit">
                Index page
            </button>
    </form>
    </div>
</body>
</html>