
<script>
// Stop the form resubmission on page refresh
if ( window.history.replaceState ) {
window.history.replaceState( null, null, window.location.href );
}
</script>

<?php

    $URL = "https://music-e281e-default-rtdb.firebaseio.com/Chats.json";
    header("refresh: 60");

    function get_messages() {
        global $URL;
        $ch = curl_init();
        curl_setopt_array($ch, [ CURLOPT_URL => $URL,
                                CURLOPT_POST => FALSE, // It will be a get request
                                CURLOPT_RETURNTRANSFER => true, ]);
        $response = curl_exec($ch);
        curl_close($ch);
        return json_decode($response, true);
    }
    
    function send_msg($msg, $support, $to) {
        global $URL;
        $ch = curl_init();
        $msg_json = new stdClass();
        $msg_json->msg = $msg;
        $msg_json->name = 'admin';
        $msg_json->to = $to;
        $msg_json->support = $support;
        $msg_json->time = date('m.d.y');
        $encoded_json_obj = json_encode($msg_json);
        curl_setopt_array($ch, array(CURLOPT_URL => $URL,
                                    CURLOPT_POST => TRUE,
                                    CURLOPT_RETURNTRANSFER => TRUE,
                                    CURLOPT_HTTPHEADER => array('Content-Type: application/json' ),
                                    CURLOPT_POSTFIELDS => $encoded_json_obj ));
        $response = curl_exec($ch);
        return $response;
    }

    $msg_res_json = get_messages();

    if (isset($_POST['to'])) {
        $user_msg = $_POST['usermsg'];
        $to = $_POST['to'];
        $support = $_POST['support'];
        send_msg($user_msg, $support, $to);
       
    }
  

?>




<!DOCTYPE html>
<html>
<head>
  <link rel="stylesheet" href="styles.css">
</head>

<div class="menu">
<div class="back"><i class="fa fa-chevron-left"></i> <img src="https://i.imgur.com/YS5S4Dy.jpeg" draggable="false"/></div>
<div class="name">Admin Panel</div>
<div class="last">Answer the users!</div>
</div>

<ol class="chat">
<?php
    $keys = array_keys($msg_res_json);
    for ($i = 0; $i < count($keys); $i++){
        $chat_msg = $msg_res_json[$keys[$i]];
        $name = $chat_msg['name'];
        $msg = $chat_msg['msg'];
        $time = $chat_msg['time'];
        $support = $chat_msg['support'];
        if ($name == 'admin') {
            $from = 'other';
        } else {
            $from = 'self';
        }
       echo  '
       <li class="'.$from.'">
       <div class="avatar">
                <img src="https://i.imgur.com/LhHhwpt.jpeg" draggable="false"/>
            </div>
                <div class="msg">
                    <p><b>'.$name.'</b></p>
                    <p>'.$support.'</p>
                    <p>'.$msg.'</p>
                    <time>'.$time.'</time>
                </div>
            </li>';
    }
?>

</ol>

<form name="the_form" action = "support.php" method="POST">
<div style="width: 100%; display: table;">
        <div style="display: table-row; height: 100px;">
            <div style="width: 50%; display: table-cell; background: #D9F2F4;">
                As an answer to: <input type="text" id="to" name="to" placeholder="Who r u responding to">
                <label for="support">Choose the relevant topic:</label>
                <select name="support" name="support">
                    <option value="Song Recommendation">Song Recommendation</option>
                    <option value="Song Background">Song Background</option>
                    <option value="Find Song by Lyrics">Find Song by Lyrics</option>
                    <option value="Suggestion">Suggestion</option>
            </div>
            <div style="display: table-cell; background: #D9F2F4;">
            </div>
        </div>
    </div>
    Message: <textarea name="usermsg" rows="5" cols="110" placeholder="Enter your message"></textarea><br>
</select>

<input type="submit" value="SEND">
</form>
