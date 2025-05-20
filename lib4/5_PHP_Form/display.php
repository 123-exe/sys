<?php
// Database connection
$conn = new mysqli('localhost', 'root', '', 'form_db');
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

$id = $_GET['id'] ?? 0;
$result = $conn->query("SELECT * FROM form_data WHERE id=$id");
if ($result->num_rows > 0) {
  $row = $result->fetch_assoc();
} else {
  die("No record found.");
}
?>
<!DOCTYPE html>
<html>

<head>
  <title>Submitted Form Data</title>
  <style>
    body {
      font-family: Arial;
      padding: 20px;
    }

    .data-item {
      margin-bottom: 10px;
    }

    .data-label {
      font-weight: bold;
      display: inline-block;
      width: 150px;
    }
  </style>
</head>

<body>
  <h2>Your Submitted Information</h2>
  <div class="data-item"><span class="data-label">Name:</span> <?= htmlspecialchars($row['name']) ?></div>

  <div class="data-item"><span class="data-label">Email:</span> <?= htmlspecialchars($row['email']) ?></div>

  <div class="data-item"><span class="data-label">Message:</span> <?= nl2br(htmlspecialchars($row['message'])) ?></div>

  <div class="data-item"><span class="data-label">Newsletter:</span> <?= htmlspecialchars($row['newsletter']) ?></div>

  <div class="data-item"><span class="data-label">Interests:</span> <?= htmlspecialchars($row['interests']) ?></div>

  <div class="data-item"><span class="data-label">Country:</span> <?= htmlspecialchars($row['country']) ?></div>

  <div class="data-item"><span class="data-label">Gender:</span> <?= htmlspecialchars($row['gender']) ?></div>

  <div class="data-item"><span class="data-label">Submitted At:</span> <?= htmlspecialchars($row['submission_date']) ?></div>

  <p style="margin-top: 20px;"><a href="form.php">Submit another form</a></p>
</body>

</html>
<?php $conn->close(); ?>
