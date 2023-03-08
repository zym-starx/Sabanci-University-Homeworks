<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
	<title>Select Doctor</title>
	
</head>

<body>
<div align="left">
    <b>Select Doctor<b>
    <br> <br>

    <form action="info-doctor.php" method="POST">
    <select name="ids">

    <?php
    include "config.php";
    $sql_command = "SELECT md_id FROM doctor";

    $myresult = mysqli_query($db, $sql_command);

    while($id_rows = mysqli_fetch_assoc($myresult))
    {
        $id = $id_rows['md_id'];
        echo "<option value=$id>".$id."</option>";
    }

    ?>
    </select>

    <button>Show</button>
    </form>

    <?php
    include "listdoctors.php";
    ?>
</div>

<div align="right">
    <form action="doctor.php">
            <button class = "gfg" type="submit">
                Doctors main page
            </button>
    </form>
</div>

</body>
</html>