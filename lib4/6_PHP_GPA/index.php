<!DOCTYPE html>
<html>

<head>
  <title>Student Grading System</title>
  <style>
    body {
      font-family: Arial;
      max-width: 600px;
      margin: 0 auto;
      padding: 20px;
    }

    label {
      display: block;
      margin: 10px 0;
      font-weight: bold;
    }

    input,
    select {
      width: 100%;
      padding: 5px;
      box-sizing: border-box;
      margin: 5px 0;
    }

    .subject-group {
      margin: 15px 0;
      padding: 10px;
      border: 1px solid #ddd;
    }

    button {
      padding: 5px 10px;
      margin: 5px;
    }
  </style>
</head>

<body>
  <h2>Student Information & Marks</h2>
  <form action="process.php" method="post">
    <label>Student Name: <input type="text" name="student_name" required></label>
    <label>Student ID: <input type="text" name="student_id" required></label>
    <label>Department:
      <select name="department" required>
        <option value="CSE">CSE</option>
        <option value="EEE">EEE</option>
        <option value="BBA">BBA</option>
      </select>
    </label>
    <label>Semester:
      <select name="semester" required>
        <option value="1st">1st</option>
        <option value="2nd">2nd</option>
        <option value="3rd">3rd</option>
      </select>
    </label>

    <div class="subject-group">
      <h3>Subject 1</h3>
      <label>Subject Name: <input type="text" name="subject1" required></label>
      <label>Marks (0-100): <input type="number" name="mark1" min="0" max="100" required></label>
    </div>

    <div class="subject-group">
      <h3>Subject 2</h3>
      <label>Subject Name: <input type="text" name="subject2" required></label>
      <label>Marks (0-100): <input type="number" name="mark2" min="0" max="100" required></label>
    </div>

    <div class="subject-group">
      <h3>Subject 3</h3>
      <label>Subject Name: <input type="text" name="subject3" required></label>
      <label>Marks (0-100): <input type="number" name="mark3" min="0" max="100" required></label>
    </div>

    <div style="text-align: center;">
      <button type="submit">Calculate GPA</button>
      <button type="reset">Reset</button>
    </div>
  </form>
</body>

</html>