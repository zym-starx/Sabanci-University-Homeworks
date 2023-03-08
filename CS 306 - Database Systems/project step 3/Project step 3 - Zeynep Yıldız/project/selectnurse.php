<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
	<title>Select Nurse</title>
	
</head>

<body>
<div align="left">
    <b>Select Nurse<b>
    <br> <br>

    <form action="info-nurse.php" method="POST">
    <select name="ids">

    <?php
    include "config.php";
    $sql_command = "SELECT nid FROM nurse";

    $myresult = mysqli_query($db, $sql_command);

    while($id_rows = mysqli_fetch_assoc($myresult))
    {
        $id = $id_rows['nid'];
        echo "<option value=$id>".$id."</option>";
    }

    ?>
    </select>

    <button>Show</button>
    </form>

    <?php
    include "listnurses.php";
    ?>
</div>

<div align="right">
    <form action="nurse.php">
            <button class = "gfg" type="submit">
                Nurses main page
            </button>
    </form>
</div>

</body>
</html>