<?php

/**
 * simple-content-banners.tpl.php
 * Template for Banners section
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */

// Banners variables: Enabled?, Header and Number
$banners_enabled = variable_get('simple_content_banners_enabled', 0);
$banners_header = variable_get('simple_content_banners_header', NULL);
$banners_number = variable_get('simple_content_banners_number', 0);

if ($banners_enabled == 1):
?>

<div class="banners-header">
  <?php if (!empty($banners_header)): ?>
  <div class="banners-header-title">
    <span class="text"><?php print $banners_header; ?></span>
  </div>
  <?php endif; ?>
</div>
<!-- Header -->

<div class="banners-content">
  <ul class="banners-content-list">
    <?php
    // Loop through number of banners
    for ($i = 1; $i <= $banners_number; $i++) {
      // Make pid two digit algarism
      $pid = str_pad($i, 2, '0', STR_PAD_LEFT);
      // Banner Enabled?
      $enabled = variable_get('simple_content_banners_' . $pid . '_enabled', 0);
      if ($enabled == 1) {
        // Clear temporary variables
        $item_id = NULL; $item_class = NULL;
        // Banner variables: Title, Thumbnail
        $item_title = variable_get('simple_content_banners_' . $pid . '_title', NULL);
        $item_thumbnail = variable_get('simple_content_banners_' . $pid . '_thumbnail', NULL);
        // Banner ids and classes
        $item_id = 'banners-content-item-' . $pid;
        $item_class = 'item';
        ?>
        <?php if (!empty($item_thumbnail)): ?>
        <li id="<?php print $item_id; ?>" class="<?php print $item_class; ?>">
          <div class="banners-content-thumbnail">
            <span class="text"><?php print $item_thumbnail; ?></span>
          </div>
        </li>
        <?php endif;
      }
    }
    ?>
  </ul>
</div>
<!-- Content -->

<div class="banners-pagers">
  <ul class="banners-pagers-list">
  </ul>
</div>
<!-- Pagers -->

<?php endif; ?>
