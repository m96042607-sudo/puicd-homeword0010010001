# 多執行緒快速排序（C + pthread）

## 📌 專案簡介
這是一個使用 **C 語言 + pthread** 實作的 **多核心加速快速排序 (Parallel QuickSort)**。  
透過遞迴切割陣列、動態產生 thread，使快速排序能在多核心 CPU 上並行執行。

## 🚀 功能特色
- 使用 pthread 實現真正多核心加速
- 自動判斷資料量，如果太小就不開 thread（避免 overhead）
- 適合高效能運算、系統程式、演算法課程專題

## 🧱 程式架構
- `partition()`：標準快速排序劃分
- `quicksort()`：單執行緒版本
- `parallel_quicksort()`：多執行緒遞迴版本
- 主程式會隨機產生 N 筆資料並排序

## 📦 編譯方式

需要支援 `pthread`：

```bash
gcc parallel_quicksort.c -o pqsort -lpthread
