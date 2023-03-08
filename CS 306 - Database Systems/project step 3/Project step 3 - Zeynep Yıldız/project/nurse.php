<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" href="style.css">
</head>
<body>
    <h2>Nurse Management</h2>
    <table>
        <th>
        <form action="viewby-nurse.php" method="POST">
            <button type="submit">View Nurses</button>
        </form>
        </th>
        <th>
        <form action="selectnurse.php" method="POST">
            <button type="submit">Select Nurse</button>
        </form>
        </th>
        <th>
        <form action="addnurse.php" method="POST">
            <button type="submit">Add Nurse</button>
        </form>
        </th>
        <th>
        <form action="deletenurse.php" method="POST">
            <button type="submit">Delete Nurse</button>
        </form>
        </th>
    </table>
    <?php
        include "listnurses.php";
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