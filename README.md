# 多執行緒快速排序 (Parallel QuickSort)

## 專案簡介
這是一個使用 **多核心加速的快速排序 (QuickSort)** 實作。  
當陣列很大時，可以利用多核心處理器來加速排序過程。

## 特性
- 自動選擇單核心或多核心排序
- 可設定最大工作進程數 (`max_workers`)
- 可設定使用多核心的陣列長度門檻 (`threshold`)

## 安裝
1. 需要 Python 3.7 以上版本
2. 建議使用虛擬環境：
```bash
python -m venv venv
source venv/bin/activate  # Linux/Mac
venv\Scripts\activate     # Windows
