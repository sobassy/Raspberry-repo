import { useState } from 'react';

import './App.css';

import Grid from '@material-ui/core/Grid';
import Slider from '@material-ui/core/Slider';
import Button from '@material-ui/core/Button';

function App() {
  const [rightPower, setRightPower] = useState(0);
  const [leftPower, setLeftPower] = useState(0);
  const [buttonVariant, setButtonVariant] = useState("outlined");
  const [synced, setSynced] = useState(false);

  const rightChange = (event, newValue) => {
    if (synced) {
      setLeftPower(newValue);
    }
    setRightPower(newValue);
  };
  const leftChange = (event, newValue) => {
    if (synced) {
      setRightPower(newValue);
    }
    setLeftPower(newValue);
  };

  const pushSync = () => {
    if (synced) {
      setSynced(false)
      setButtonVariant("outlined")
    } else {
      setSynced(true)
      setButtonVariant("contained")
    }
  }

  return (
    <div className="App">
      <header className="App-header">
      <Grid container width="100vw">
          <Grid item xs={1}></Grid>
          <Grid item xs={4}>
            LEFT POWER
          </Grid>
          <Grid item xs={2}>
          </Grid>
          <Grid item xs={4}>
            RIGHT POWER
          </Grid>
          <Grid item xs={1}></Grid>
        </Grid>
        <Grid container width="100vw">
          <Grid item xs={1}></Grid>
          <Grid item xs={4}>
            <Slider value={leftPower} onChange={leftChange} aria-labelledby="continuous-slider" />
          </Grid>
          <Grid item xs={2}>
            <Button variant={buttonVariant} color="primary" onClick={pushSync}>sync</Button>
          </Grid>
          <Grid item xs={4}>
            <Slider value={rightPower} onChange={rightChange} aria-labelledby="continuous-slider" />
          </Grid>
          <Grid item xs={1}></Grid>
        </Grid>
      </header>
    </div>
  );
}

export default App;
