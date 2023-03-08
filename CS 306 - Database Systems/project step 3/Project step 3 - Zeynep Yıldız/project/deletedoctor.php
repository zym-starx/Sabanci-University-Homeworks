<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
	<title>Delete Doctor</title>
	
</head>

<body>
<div align="left">
    <b>Delete Doctor<b>
    <br> <br>

    <?php
    include "listdoctors.php";
    ?>

    <form action="deletedoctor2.php" method="POST">
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

    <button>DELETE</button>
    </form>
</div>
<br><br>

<div align="left">
    <form action="doctor.php">
            <button class = "gfg" type="submit">
                Doctors main page
            </button>
    </form>
</div>

</body>
</html>