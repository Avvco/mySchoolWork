# Read the CSV files
df_KB <- read.csv("KB.csv")
df_LJ <- read.csv("LJ.csv")
df_MJ <- read.csv("MJ.csv")

# Combine the dataframes and add a player column
df_combined <- rbind(df_KB, df_LJ, df_MJ)
df_combined$Player <- c(rep("Kobe Bryant", nrow(df_KB)), rep("LeBron James", nrow(df_LJ)), rep("Michael Jordan", nrow(df_MJ)))

# Calculate Efficiency for each row
df_combined$Efficiency <- with(df_combined, (PTS + TRB + AST + STL + BLK - (FGA - FG) - (FTA - FT) - TOV) / G)

# Aggregate to career efficiency
career_efficiency <- aggregate(Efficiency ~ Player, df_combined, sum)

# Ensure Efficiency is not less than 1 (as per the requirement)
career_efficiency$Efficiency[career_efficiency$Efficiency < 1] <- 1

# Sort by efficiency (optional, for better visualization)
career_efficiency <- career_efficiency[order(career_efficiency$Efficiency), ]

# Plotting (using base R graphics)
bar_positions <- barplot(career_efficiency$Efficiency, 
                        names.arg = career_efficiency$Player, 
                        col = c("purple", "gold", "red"),  # Lakers, Cavs, Bulls colors
                        xlab = "Player", 
                        ylab = "Career Efficiency",
                        ylim = c(0, max(career_efficiency$Efficiency) * 1.1)) # Add some space on top

# Add the efficiency values on top of the bars
text(bar_positions, career_efficiency$Efficiency, 
     labels = round(career_efficiency$Efficiency, 2), 
     pos = 3, cex = 0.8)
