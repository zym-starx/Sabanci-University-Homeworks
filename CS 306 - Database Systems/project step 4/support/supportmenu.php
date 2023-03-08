<head>
<link rel="stylesheet" href="styles.css">
</head>
<body>

<div align="left">
<h1> ~~~ Hospital Admin Support ~~~</h1>
<h2> If you want to see the status of your ticket please only write your name</h2>
<h2> <br> Otherwise open a new ticket. </h2>

</form>
<form action="chat-guest.php" method="POST">
Name: <input type="text" id="current_name" name="current_name">
<input type="submit" value="Submit">
</form>

<h2 style="color: #627EED; font-size:100%;"> Open a new ticket below</h2>


</form>



<form name="the_form" action = "chat-guest.php" method="POST">
<div style="width: 100%; display: table;">
        <div style="display: table-row; height: 100px;">
            <div style="width: 50%; display: table-cell; background: #D9F2F4;">
                Username: <input type="text" id="username" name="username" placeholder="Type your name">
                <label for="support">Choose the relevant setting you want to edit:</label>
                <select name="support" name="support">
                    <option value="Patient Settings">Patient Settings</option>
                    <option value="Doctor Settings">Doctor Settings</option>
                    <option value="Nurse Settings">Nurse Settings</option>
                    <option value="Medical Record Settings">Medical Record Settings</option>
            </div>
            <div style="display: table-cell; background: #D9F2F4;">
            Message: <textarea name="usermsg" rows="5" cols="165" placeholder="Enter your message"></textarea>

            </div>
        </div>
    </div>
   
</select>

<input type="submit" value="SEND">
</form>
