<style>
input[type=text], select {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
}
input[type=submit] { /* submit buttons color */
  width: 100%;
  background-color: #849BF4;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  border-radius: 4px;
  cursor: pointer;
}
input[type=submit]:hover { /* color the button gets when clicked.*/
  background-color: #627EED;
}
.button2 {
  background-color: #45a049;
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
  }
div {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
}
</style>
</head>
<body>

<div align="center">
<h1 style="color: #627EED; font-size:150%;"> ~~~ Welcome to our support page ! ~~~</h1>
<h2 style="color: #627EED; font-size:100%;"> Write your name if you requested support before, otherwise open a new ticket </h2>

</form>
<form action="chats.php" method="POST">
Name: <input type="text" id="current_name" name="current_name">
<input type="submit" value="Submit">
</form>


<img src="https://i.imgur.com/FKuqFp7.gif" draggable="false"/>
<h2 style="color: #627EED; font-size:100%;"> Open a new ticket below :) </h2>


</form>



<form name="the_form" action = "chats.php" method="POST">
<div style="width: 100%; display: table;">
        <div style="display: table-row; height: 100px;">
            <div style="width: 50%; display: table-cell; background: #D9F2F4;">
                Username: <input type="text" id="username" name="username" placeholder="Type your name">
                <label for="support">Choose the relevant topic:</label>
                <select name="support" name="support">
                  <option value="Song Recommendation">Song Recommendation</option>
                  <option value="Song Background">Song Background</option>
                  <option value="Find Song by Lyrics">Find Song by Lyrics</option>
                  <option value="Suggestion">Suggestion</option>
            </div>
            <div style="display: table-cell; background: #D9F2F4;">
            Message: <textarea name="usermsg" rows="5" cols="165" placeholder="Enter your message"></textarea>

            </div>
        </div>
    </div>
   
</select>

<input type="submit" value="SEND">
</form>
