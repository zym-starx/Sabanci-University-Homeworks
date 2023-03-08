<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="style.css">
</head>
<body>
    <h2>Doctor Management</h2>
    <table>
        <th>
        <form action="viewby-doctor.php" method="POST">
            <button type="submit">View Doctors</button>
        </form>
        </th>
        <th>
        <form action="selectdoctor.php" method="POST">
            <button type="submit">Select Doctor</button>
        </form>
        </th>
        <th>
        <form action="adddoctor.php" method="POST">
            <button type="submit">Add Doctor</button>
        </form>
        </th>
        <th>
        <form action="deletedoctor.php" method="POST">
                <button type="submit">Delete Doctor</button>
        </form>
       </th>
    </table>
    <?php
        include "listdoctors.php";
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