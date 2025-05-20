<?php
// Database connection
$conn = new mysqli('localhost', 'root', '', 'student_grading');
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

// Get form data
$student_name = $conn->real_escape_string($_POST['student_name']);
$student_id = $conn->real_escape_string($_POST['student_id']);
$department = $conn->real_escape_string($_POST['department']);
$semester = $conn->real_escape_string($_POST['semester']);
$subject1 = $conn->real_escape_string($_POST['subject1']);
$mark1 = intval($_POST['mark1']);
$subject2 = $conn->real_escape_string($_POST['subject2']);
$mark2 = intval($_POST['mark2']);
$subject3 = $conn->real_escape_string($_POST['subject3']);
$mark3 = intval($_POST['mark3']);

// Calculate GPA and Grade
function calculateGPA($mark) {
  if ($mark >= 80) return ['gpa' => 4.0, 'grade' => 'A+'];
  if ($mark >= 75) return ['gpa' => 3.75, 'grade' => 'A'];
  if ($mark >= 70) return ['gpa' => 3.5, 'grade' => 'A-'];
  if ($mark >= 65) return ['gpa' => 3.25, 'grade' => 'B+'];
  if ($mark >= 60) return ['gpa' => 3.0, 'grade' => 'B'];
  if ($mark >= 55) return ['gpa' => 2.75, 'grade' => 'B-'];
  if ($mark >= 50) return ['gpa' => 2.5, 'grade' => 'C+'];
  if ($mark >= 45) return ['gpa' => 2.25, 'grade' => 'C'];
  if ($mark >= 40) return ['gpa' => 2.0, 'grade' => 'D'];
  return ['gpa' => 0.0, 'grade' => 'F'];
}

$gpa1 = calculateGPA($mark1);
$gpa2 = calculateGPA($mark2);
$gpa3 = calculateGPA($mark3);

$average_gpa = ($gpa1['gpa'] + $gpa2['gpa'] + $gpa3['gpa']) / 3;

// Determine overall grade based on average GPA
if ($average_gpa >= 3.75) $overall_grade = 'A';
elseif ($average_gpa >= 3.5) $overall_grade = 'A-';
elseif ($average_gpa >= 3.25) $overall_grade = 'B+';
elseif ($average_gpa >= 3.0) $overall_grade = 'B';
elseif ($average_gpa >= 2.75) $overall_grade = 'B-';
elseif ($average_gpa >= 2.5) $overall_grade = 'C+';
elseif ($average_gpa >= 2.25) $overall_grade = 'C';
elseif ($average_gpa >= 2.0) $overall_grade = 'D';
else $overall_grade = 'F';

// Insert into database
$sql = "INSERT INTO student_records (student_name, student_id, department, semester, 
        subject1, mark1, subject2, mark2, subject3, mark3, gpa, grade)
        VALUES ('$student_name', '$student_id', '$department', '$semester',
        '$subject1', $mark1, '$subject2', $mark2, '$subject3', $mark3, 
        $average_gpa, '$overall_grade')";

if ($conn->query($sql)) {
  $last_id = $conn->insert_id;
  header("Location: result.php?id=$last_id");
} else {
  echo "Error: " . $conn->error;
}

$conn->close();
?>
