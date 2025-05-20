<?php
$conn = new mysqli('localhost', 'root', '', 'student_grading');
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

$id = $_GET['id'] ?? 0;
$result = $conn->query("SELECT * FROM student_records WHERE id=$id");
if ($result->num_rows > 0) {
  $student = $result->fetch_assoc();
} else {
  die("No record found.");
}
?>
<!DOCTYPE html>
<html>

<head>
  <title>Student Results</title>
  <style>
    body {
      font-family: Arial;
      margin: 20px auto;
      max-width: 800px;
    }

    table {
      width: 100%;
      border: 1px solid;
      border-collapse: collapse;
    }

    th,
    td {
      border: 1px solid;
      padding: 5px;
    }
  </style>
</head>

<body>
  <div style="border:1px solid; padding:15px; margin-bottom:15px;">
    <div style="text-align:center; margin-bottom:15px;">
      <h2 style="margin:5px 0">Student Grade Report</h2>
      <p style="margin:5px 0">University Grading System</p>
    </div>

    <div>
      <p><strong>Student Name:</strong> <?= htmlspecialchars($student['student_name']) ?></p>
      <p><strong>Student ID:</strong> <?= htmlspecialchars($student['student_id']) ?></p>
      <p><strong>Department:</strong> <?= htmlspecialchars($student['department']) ?></p>
      <p><strong>Semester:</strong> <?= htmlspecialchars($student['semester']) ?></p>
    </div>

    <table>
      <tr>
        <th>Subject</th>
        <th>Marks</th>
        <th>Grade</th>
      </tr>
      <tr>
        <td><?= htmlspecialchars($student['subject1']) ?></td>
        <td><?= $student['mark1'] ?></td>
        <td><?= calculateGrade($student['mark1']) ?></td>
      </tr>
      <tr>
        <td><?= htmlspecialchars($student['subject2']) ?></td>
        <td><?= $student['mark2'] ?></td>
        <td><?= calculateGrade($student['mark2']) ?></td>
      </tr>
      <tr>
        <td><?= htmlspecialchars($student['subject3']) ?></td>
        <td><?= $student['mark3'] ?></td>
        <td><?= calculateGrade($student['mark3']) ?></td>
      </tr>
    </table>

    <div style="margin-top:15px; font-weight:bold;">
      <p>GPA: <?= number_format($student['gpa'], 2) ?></p>
      <p>Overall Grade: <?= $student['grade'] ?></p>
    </div>
  </div>

  <p><a href="index.php">Enter another student</a></p>
</body>

</html>
<?php
function calculateGrade($mark)
{
  if ($mark >= 80) return 'A+';
  if ($mark >= 75) return 'A';
  if ($mark >= 70) return 'A-';
  if ($mark >= 65) return 'B+';
  if ($mark >= 60) return 'B';
  if ($mark >= 55) return 'B-';
  if ($mark >= 50) return 'C+';
  if ($mark >= 45) return 'C';
  if ($mark >= 40) return 'D';
  return 'F';
}
$conn->close();
?>