<?php

/**
 * simple-content-solutions.tpl.php
 * Template for Solutions section
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */

// Solutions variables: Enabled?, Header and Number
$solutions_enabled = variable_get('simple_content_solutions_enabled', 0);
$solutions_header = variable_get('simple_content_solutions_header', NULL);
$solutions_number = variable_get('simple_content_solutions_number', 0);

if ($solutions_enabled == 1):
?>

<div class="solutions-header">
  <?php if (!empty($solutions_header)): ?>
  <div class="solutions-header-title">
    <span class="text"><?php print $solutions_header; ?></span>
  </div>
  <?php endif; ?>
</div>
<!-- Header -->

<div class="solutions-content">
  <ul class="solutions-content-list">
    <?php
    // Loop through number of solutions
    for ($i = 1; $i <= $solutions_number; $i++) {
      // Make pid two digit algarism
      $pid = str_pad($i, 2, '0', STR_PAD_LEFT);
      // Solution Enabled?
      $enabled = variable_get('simple_content_solutions_' . $pid . '_enabled', 0);
      if ($enabled == 1) {
        // Clear temporary variables
        $item_id = NULL; $item_class = NULL;
        // Solution variables: Title, Body, Thumbnail
        $item_title = variable_get('simple_content_solutions_' . $pid . '_title', NULL);
        $item_body = variable_get('simple_content_solutions_' . $pid . '_body', NULL);
        $item_thumbnail = variable_get('simple_content_solutions_' . $pid . '_thumbnail', NULL);
        // Solution ids and classes
        $item_id = 'solutions-content-item-' . $pid;
        $item_class = 'item';
        ?>
        <li id="<?php print $item_id; ?>" class="<?php print $item_class; ?>">
          <div class="content-twocol-stacked">

            <div class="content-twocol-stacked-top">

              <?php if (!empty($item_title)): ?>
              <div class="solutions-content-title">
                <span class="text"><?php print $item_title; ?></span>
              </div>
              <?php endif; ?>

            </div>
            <!-- Top Row -->

            <div class="content-twocol-stacked-bottom">

              <?php if (!empty($item_body)): ?>
              <div class="content-twocol-stacked-left">
                <div class="solutions-content-body">
                  <span class="text"><?php print $item_body; ?></span>
                </div>
              </div>
              <?php endif; ?>
              <!-- Left Column -->

              <?php if (!empty($item_thumbnail)): ?>
              <div class="content-twocol-stacked-right">
                <div class="solutions-content-thumbnail">
                  <span class="text"><?php print $item_thumbnail; ?></span>
                </div>
              </div>
              <?php endif; ?>
              <!-- Right Column -->

            </div>
            <!-- Bottom Row -->

          </div>
        </li>
        <?php
      }
    }
    ?>
  </ul>
</div>
<!-- Content -->

<div class="solutions-menu">
  <ul class="solutions-menu-list">
    <?php
    // Loop through number of solutions
    for ($i = 1; $i <= $solutions_number; $i++) {
      // Make pid two digit algarism
      $pid = str_pad($i, 2, '0', STR_PAD_LEFT);
      // Solution Enabled?
      $enabled = variable_get('simple_content_solutions_' . $pid . '_enabled', 0);
      if ($enabled == 1) {
        // Clear temporary variables
        $item_id = NULL; $item_class = NULL;
        // Solution Menu Title
        $item_title = variable_get('simple_content_solutions_' . $pid . '_menu', NULL);
        // Solution classes
        $item_class = 'item item-' . $pid;
        switch ($i) {
          // First menu item
          case 1:
            $item_class .= ' first';
            break;
          // Last menu item
          case $solutions_number:
            $item_class .= ' last';
            break;
        }
        ?>
        <?php if (!empty($item_title)): ?>
        <li class="<?php print $item_class; ?>">
          <a href="#solutions-content-item-<?php print $pid; ?>"><?php print $item_title; ?></a>
        </li>
        <?php endif;
      }
    }
    ?>
  </ul>
</div>
<!-- Menu -->

<div class="solutions-footer">
  <div class="solutions-footer-background">
    <img src="" />
  </div>
</div>
<!-- Footer -->

<?php endif; ?>
