#include <cstring>
#include <iostream>

using namespace std;

bool clientHasPiece[100][200]; // наличие куска у клиента

int numClientsWithPiece[200], desiredPieceNumOfClient[100], numPiecesOfClient[100], clientFromWhomClientWantsToDownload[100], clientToWhomClientWillDownload[100], clientValue[100][100], clientDownloadCompleteRound[100];

int main()
{
    int numClients, numPieces;
    cin >> numClients >> numPieces;

    for (int i = 0; i < numPieces; ++i)
    {
        clientHasPiece[0][i] = true;
        numClientsWithPiece[i] = 1;
    }

    memset(clientValue, 0, sizeof(clientValue));
    memset(numPiecesOfClient, 0, sizeof(numPiecesOfClient));
    numPiecesOfClient[0] = numPieces;
    memset(clientDownloadCompleteRound, -1, sizeof(clientDownloadCompleteRound));

    int totalDownloads = (numClients - 1) * numPieces, numIterations = 0;
    while (totalDownloads)
    {
        memset(desiredPieceNumOfClient, -1, sizeof(desiredPieceNumOfClient));
        for (int i = 0; i < numClients; ++i)
        {
            for (int j = 0; j < numPieces; ++j)
            {
                if (!clientHasPiece[i][j] && (desiredPieceNumOfClient[i] < 0 || numClientsWithPiece[desiredPieceNumOfClient[i]] > numClientsWithPiece[j]))
                {
                    desiredPieceNumOfClient[i] = j;
                }
            }
        }

        // этот фрагмент нужен
        memset(clientFromWhomClientWantsToDownload, -1, sizeof(clientFromWhomClientWantsToDownload));
        for (int i = 0; i < numClients; ++i)
        {
            if (desiredPieceNumOfClient[i] < 0)
            {
                continue; // этот фрагмент нам не нужен
            }

            int desiredPieceNum = desiredPieceNumOfClient[i];
            for (int j = 0; j < numClients; ++j)
            {
                if (clientHasPiece[j][desiredPieceNum] && (clientFromWhomClientWantsToDownload[i] < 0 || numPiecesOfClient[clientFromWhomClientWantsToDownload[i]] > numPiecesOfClient[j]))
                {
                    clientFromWhomClientWantsToDownload[i] = j;
                }
            }
        }

        memset(clientToWhomClientWillDownload, -1, sizeof(clientToWhomClientWillDownload));
        for (int i = 0; i < numClients; ++i)
        {
            if (clientFromWhomClientWantsToDownload[i] < 0)
            {
                continue; // этот клиент нам не подходит
            }

            int clientToDownloadFrom = clientFromWhomClientWantsToDownload[i];
            if (clientToWhomClientWillDownload[clientToDownloadFrom] < 0 ||
                clientValue[clientToDownloadFrom][clientToWhomClientWillDownload[clientToDownloadFrom]] < clientValue[clientToDownloadFrom][i] ||
                (clientValue[clientToDownloadFrom][clientToWhomClientWillDownload[clientToDownloadFrom]] == clientValue[clientToDownloadFrom][i] && numPiecesOfClient[clientToWhomClientWillDownload[clientToDownloadFrom]] > numPiecesOfClient[i]))
            {
                clientToWhomClientWillDownload[clientToDownloadFrom] = i;
            }
        }

        for (int i = 0; i < numClients; ++i)
        {

            if (clientToWhomClientWillDownload[i] < 0)
            {
                continue;
            }

            --totalDownloads;
            ++clientValue[clientToWhomClientWillDownload[i]][i];
            ++numPiecesOfClient[clientToWhomClientWillDownload[i]];
            ++numClientsWithPiece[desiredPieceNumOfClient[clientToWhomClientWillDownload[i]]];
            clientHasPiece[clientToWhomClientWillDownload[i]][desiredPieceNumOfClient[clientToWhomClientWillDownload[i]]] = true;
            if (numPiecesOfClient[clientToWhomClientWillDownload[i]] == numPieces)
            {
                clientDownloadCompleteRound[clientToWhomClientWillDownload[i]] = numIterations + 1;
            }
        }
        ++numIterations;
    }

    for (int i = 1; i < numClients; ++i)
    {
        cout << clientDownloadCompleteRound[i] << " ";
    }

    return 0;
}