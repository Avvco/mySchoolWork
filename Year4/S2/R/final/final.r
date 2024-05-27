calculator <- function() {
  cat("Simple Calculator (Input from stdin)\n")
  cat("Available operations: +, -, *, /\n")
  cat("Enter calculations in the format: num1 operator num2\n")
  cat("Type 'quit' to exit\n")

  while (TRUE) {
    input <- readLines(con = "stdin", n = 1) 
    if (input == "quit") {
      break
    }
    
    parts <- strsplit(input, " ")[[1]] 
    num1 <- as.numeric(parts[1])
    operator <- parts[2]
    num2 <- as.numeric(parts[3])

    if (!is.na(num1) && !is.na(num2) && operator %in% c("+", "-", "*", "/")) { 
      result <- switch(operator,
                       "+" = num1 + num2,
                       "-" = num1 - num2,
                       "*" = num1 * num2,
                       "/" = num1 / num2,
                       stop("Invalid operator")
      )
      cat("Result:", result, "\n")
    } else {
      cat("Invalid input. Please use the correct format.\n")
    }
  }
}

# Run the calculator
calculator()
