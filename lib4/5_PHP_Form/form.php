<!DOCTYPE html>
<html>

<head>
  <title>PHP Form Experiment</title>
  <style>
    body {
      font-family: Arial;
      padding: 20px;
    }

    label {
      font-weight: bold;
      display: block;
      margin-top: 10px;
    }

    textarea {
      display: block;
      margin-top: 5px;
    }

    fieldset {
      width: 50%;
      margin: 10px 0;
      padding: 10px;
    }

    .buttons {
      margin-top: 15px;
    }
  </style>
</head>

<body>
  <h2>User Information Form</h2>
  <form action="submit.php" method="post">
    <label>Full Name:
      <input type="text" name="name" required style="display:block;">
    </label>

    <label>Email:
      <input type="email" name="email" required style="display:block;">
    </label>

    <!-- Text Area (NOT required) -->
    <label>Your Message:</label>
    <textarea name="message" rows="4"></textarea>

    <!-- Radio Buttons (Required using one input) -->
    <fieldset>
      <legend>Subscribe to Newsletter:</legend>
      <label><input type="radio" name="newsletter" value="Yes" required> Yes</label>
      <label><input type="radio" name="newsletter" value="No"> No</label>
    </fieldset>

    <!-- Checkboxes (Ideally require at least one using JS) -->
    <fieldset>
      <legend>Your Interests:</legend>
      <label><input type="checkbox" name="interests[]" value="Sports" required> Sports</label>
      <label><input type="checkbox" name="interests[]" value="Music"> Music</label>
      <label><input type="checkbox" name="interests[]" value="Technology"> Technology</label>
    </fieldset>

    <!-- Select List (Make sure a country is selected) -->
    <label>Country:
      <select name="country" required>
        <option value="">-- Select --</option>
        <option value="USA">United States</option>
        <option value="UK">United Kingdom</option>
        <option value="Canada">Canada</option>
        <option value="Australia">Australia</option>
      </select>
    </label>

    <!-- Gender Radio Buttons -->
    <fieldset>
      <legend>Gender:</legend>
      <label><input type="radio" name="gender" value="Male" required> Male</label>
      <label><input type="radio" name="gender" value="Female"> Female</label>
      <label><input type="radio" name="gender" value="Other"> Other</label>
    </fieldset>

    <!-- Password Field -->
    <label>Password: <input type="password" name="password" required></label>

    <!-- Buttons -->
    <div class="buttons">
      <button type="submit">Submit Form</button>
      <button type="reset">Clear Form</button>
    </div>
  </form>
</body>

</html>
