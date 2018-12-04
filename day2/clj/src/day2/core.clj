(ns day2.core
	(:require clojure.set clojure.string)
  (:gen-class))

(defn filter-and-count-by-freq
	[n coll]
	(->> coll
			 (map frequencies)
			 (map clojure.set/map-invert)
			 (filter #(contains? % n))
			 (count)))

(defn part-one
	[coll]
	(* (filter-and-count-by-freq 2 coll) (filter-and-count-by-freq 3 coll)))

(defn -main
  "Day 2"
  [filename]
  (println
	 (part-one
		(clojure.string/split-lines (slurp filename)))))
