<?php
// Database connection
$conn = new mysqli('localhost', 'root', '', 'form_db');
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

// Sanitize and prepare data
$name = $conn->real_escape_string($_POST['name']);
$email = $conn->real_escape_string($_POST['email']);
$message = $conn->real_escape_string($_POST['message']);
$newsletter = $_POST['newsletter'] ?? 'No';
$interests = implode(", ", $_POST['interests'] ?? []);
$country = $_POST['country'] ?? '';
$gender = $_POST['gender'] ?? '';
$password = password_hash($_POST['password'], PASSWORD_DEFAULT);

// Insert query
$sql = "INSERT INTO form_data (name, email, message, newsletter, interests, country, gender, password)
        VALUES ('$name', '$email', '$message', '$newsletter', '$interests', '$country', '$gender', '$password')";

if ($conn->query($sql)) {
  $last_id = $conn->insert_id;
  header("Location: display.php?id=$last_id");
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
