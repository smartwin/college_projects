<?php 

$to = "myia.dickens@gmail.com";
$subject = "Your website form information";

// Process message
$message = "";
foreach ($_POST as $key => $value) {
$message .= "$key : $value \n";
}
// Show message on page
echo nl2br($message);

// Actually Mail it
mail($to,$subject,$message);
?>

<button onclick="goBack()">Go Back</button>

<script>
function goBack() {
window.history.back();
}
</script>