<!DOCTYPE html>
<html>
<head>
    <title>MAIN PAGE</title>
</head>
<body>
    <div align="center">
        <b>Hospital Management System</b>
        <br>
        <b>(Only Patients table (atm))</b>
        <br>
        <br>
    </div>
<?php
    include "patients.php"
?>    
    <br>
    <form action="addpatient.php" method="POST">
        <button type="submit">Add Patient</button>
    </form>
    <br>
    <form action="deletepatient.php" method="POST">
        <button type="submit">Delete Patient</button>
    </form>
    <br>
    <form action="selectpatient.php" method="POST">
        <button type="submit">Select Patient</button>
    </form>

</body>

</html>