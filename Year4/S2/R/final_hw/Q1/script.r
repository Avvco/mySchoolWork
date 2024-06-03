# Error Handling for File Reading
tryCatch({
  # Read the CSV file
  Hyper <- read.csv("Dataset.csv")  
 
  # Create the 'Hypertension' column based on 'SBP' values
  Hyper$Hypertension <- ifelse(Hyper$SBP >= 140, 1, 0)

  # Display the first few rows of the data frame (optional)
  print(head(Hyper))

  # Calculate and print the number of patients with hypertension
  num_hypertension <- sum(Hyper$Hypertension)
  cat("[1]", num_hypertension, "\n") 
  
}, error = function(e) {
  # Handle file reading errors gracefully
  message("Error reading the file. Please check the file name and path.")
  print(e)
})
