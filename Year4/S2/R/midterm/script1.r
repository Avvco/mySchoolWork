# Q1
cat(noquote("=============== Q1 ===============\n"))
花蓮縣鄉鎮市名 <- c("花蓮縣", "花蓮市", "鳳林鄉", "玉里鎮", "新城鄉", "吉安鄉", "壽豐鄉", "光復鄉", "豐濱鄉", "瑞穗鄉", "富里鄉", "秀林鄉", "萬榮鄉", "卓溪鄉")
花蓮縣各鄉鎮人口數 <- c(318863, 99516, 10552, 22356, 20308, 82840, 17119, 11975, 4310, 10941, 9681, 17068, 6154, 6043)

# print this two vecter together with header
setNames(aggregate(花蓮縣各鄉鎮人口數, by = list(花蓮縣鄉鎮市名), sum), c("花蓮縣鄉鎮市名", "花蓮縣各鄉鎮人口數"))
cat("\n")

# ========================
# Q2
cat(noquote("=============== Q2 ===============\n"))
花蓮縣各鄉鎮面積_平方公里 <- c(4628, 29, 120, 252, 29, 65, 218, 157, 162, 135, 176, 1641, 618, 1021)

setNames(aggregate(花蓮縣各鄉鎮面積_平方公里, by = list(花蓮縣鄉鎮市名), sum), c("花蓮縣鄉鎮市名", "花蓮縣各鄉鎮面積_平方公里"))
cat("\n")

# ========================
# Q3
cat(noquote("=============== Q3 ===============\n"))
# a vector of population density
花蓮縣各鄉鎮人口密度 <- 花蓮縣各鄉鎮人口數 / 花蓮縣各鄉鎮面積_平方公里

setNames(aggregate(花蓮縣各鄉鎮人口密度, by = list(花蓮縣鄉鎮市名), mean), c("花蓮縣鄉鎮市名", "花蓮縣各鄉鎮人口密度"))
cat("\n")

# ========================
# Q4
cat(noquote("=============== Q4 ===============\n"))
# a matrix of population growth table
花蓮縣各鄉鎮人口成長率 <- matrix(c(160701, 160602, 158191, 158261, 318892, 318863), nrow = 3, byrow = TRUE)
rownames(花蓮縣各鄉鎮人口成長率) <- c("男", "女", "合計")
colnames(花蓮縣各鄉鎮人口成長率) <- c("111年", "112年2月")

print(花蓮縣各鄉鎮人口成長率)
cat("\n")

# ========================
# Q5
cat(noquote("=============== Q5 ===============\n"))
# a dataframe containing all the information
花蓮縣人口相關資料表 <- data.frame(花蓮縣鄉鎮市名, 花蓮縣各鄉鎮人口數, 花蓮縣各鄉鎮面積_平方公里, 花蓮縣各鄉鎮人口密度)
setNames(花蓮縣人口相關資料表, c("花蓮縣鄉鎮市名", "花蓮縣各鄉鎮人口數", "花蓮縣各鄉鎮面積_平方公里", "花蓮縣各鄉鎮人口密度"))
cat("\n")

# ========================
# Q6
cat(noquote("=============== Q6 ===============\n"))
# a list of all the vectors, arrays and dataframes
花蓮縣人口相關列表 <- list(花蓮縣鄉鎮市名, 花蓮縣各鄉鎮人口數, 花蓮縣各鄉鎮面積_平方公里, 花蓮縣各鄉鎮人口密度, 花蓮縣各鄉鎮人口成長率, 花蓮縣人口相關資料表)
setNames(花蓮縣人口相關列表, c("花蓮縣鄉鎮市名", "花蓮縣各鄉鎮人口數", "花蓮縣各鄉鎮面積", "花蓮縣人口密度", "花蓮縣人口成長", "花蓮縣人口相關資料"))
cat("\n")

# ========================
# Q7
cat(noquote("=============== Q7 ===============\n"))
# wait for user input then query for the information
cat("請輸入要查詢人口數的地點: ")
cat("$ ")
town_name <- readLines("stdin",n=1)
# cat(town_name, "\n")
town_index <- which(花蓮縣鄉鎮市名 == town_name)
if (length(town_index) == 0) {
  cat("The town you entered does not exist in the list.\n")
} else {
  cat("The population of ", town_name, " is ", 花蓮縣各鄉鎮人口數[town_index], ".\n")
}