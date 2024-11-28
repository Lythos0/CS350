void undo()
{
    if (!records.empty())
    {
        string s = records.top();
        records.pop();
        int d = stoi(s[0]);
        int p = stoi(s.substr(1));
        board[p] = d;
    }
}
