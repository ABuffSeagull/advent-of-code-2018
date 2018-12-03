(ns	day1.core
	(:gen-class))

(defn	-main
	"Day 1!"
	[filename]
	(println
	 	(reduce +
		 	(map
			 	#(Integer/parseInt %)
				(clojure.string/split-lines
					(slurp filename))))))
