while(running)
{
    handleEvents();

    updateBall(&ball);

    updateGame();

    renderScene(renderer);
}