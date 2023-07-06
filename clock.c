        // Calcul du temps écoulé
        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - startTime;

        // Conversion en secondes
        Uint32 seconds = elapsedTime / 1000;

        // Conversion en minutes et secondes
        Uint32 minutes = seconds / 60;
        Uint32 remainingSeconds = seconds % 60;

        // Affichage du chronomètre
        char timerText[10];
        sprintf(timerText, "%02d:%02d", minutes, remainingSeconds);

        SDL_Surface* textSurface = TTF_RenderText_Solid(font, timerText, textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth = textSurface->w;
        int textHeight = textSurface->h;

        SDL_Rect textRect;
        textRect.x = (WINDOW_WIDTH - textWidth) / 2;
        textRect.y = (WINDOW_HEIGHT - textHeight) / 2;
        textRect.w = textWidth;
        textRect.h = textHeight;

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        SDL_RenderPresent(renderer);
